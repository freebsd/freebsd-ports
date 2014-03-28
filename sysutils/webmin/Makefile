# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	webmin
PORTVERSION=	1.680
CATEGORIES=	sysutils
MASTER_SITES=	http://download.webmin.com/updates/:up \
		SF/webadmin/${PORTNAME}/${PORTVERSION}:sf \
		${MASTER_SITE_LOCAL:S/$/:up/}
MASTER_SITE_SUBDIR=	olgeni/:up
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sf ${WEBMIN_MODULES:S/gz$/gz:up/}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Web-based interface for system administration for Unix

RUN_DEPENDS=	p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-IO-Tty>=0:${PORTSDIR}/devel/p5-IO-Tty \
		p5-Authen-PAM>=0:${PORTSDIR}/security/p5-Authen-PAM

USES=		perl5
USE_PYTHON=	yes
USE_RC_SUBR=	webmin
SUB_LIST=	PERL5=${PERL}
SUB_FILES=	pkg-message

WEBMIN_MODULES=

post-extract:
	@${RM} -f ${WRKSRC}/mount/freebsd-mounts-?
	@if [ "${WEBMIN_MODULES}" != "" ]; then \
		for webmin_module in ${WEBMIN_MODULES}; do \
			${ECHO} "===> Unpacking updated module: $${webmin_module}"; \
			${TAR} --unlink -xzf ${DISTDIR}/$${webmin_module} -C ${WRKSRC}; \
		done; \
	fi
	@${FIND} ${WRKSRC} -name .xvpics | ${XARGS} ${RM} -r

post-patch:
	@${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@g" ${WRKSRC}/setup.sh

	@${FIND} ${WRKSRC} -name config-freebsd\* \
		-exec ${REINPLACE_CMD} -e "s@/usr/local@${PREFIX}@g" {} \; \
		-exec ${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@g" {} \;

	@${FIND} ${WRKSRC} -name "*.cgi" -exec \
		${REINPLACE_CMD} -e "s@#!/usr/local/bin/perl@#!${PERL}@" {} \;
	@${FIND} ${WRKSRC} -name "*.cgi" -exec \
		${REINPLACE_CMD} -e "s@#!/usr/bin/perl@#!${PERL}@" {} \;
	@${FIND} ${WRKSRC} -name "*.pl" -exec \
		${REINPLACE_CMD} -e "s@#!/usr/local/bin/perl@#!${PERL}@" {} \;
	@${FIND} ${WRKSRC} -name "*.pl" -exec \
		${REINPLACE_CMD} -e "s@#!/usr/bin/perl@#!${PERL}@" {} \;

	@${FIND} ${WRKSRC} -name "*.orig" -delete
	@${FIND} ${WRKSRC} -name "*.bak" -delete
	@${FIND} ${WRKSRC} -name "*.pyc" -delete

	@${PRINTF} "g/^FreeBSD/m0\nwq\n" | ex ${WRKSRC}/os_list.txt

do-build:
	@${PYTHON_CMD} -mcompileall ${WRKSRC}/ajaxterm/ajaxterm/
	@${PYTHON_CMD} -O -mcompileall ${WRKSRC}/ajaxterm/ajaxterm/
	@${CC} ${CFLAGS} -o ${WRKSRC}/mount/freebsd-mounts-7 ${WRKSRC}/mount/freebsd-mounts-7.c

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/webmin
	${CP} -r ${WRKSRC}/* ${STAGEDIR}${PREFIX}/lib/webmin

.include <bsd.port.mk>
