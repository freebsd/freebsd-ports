# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	webmin
PORTVERSION=	1.950
CATEGORIES=	sysutils
MASTER_SITES=	http://download.webmin.com/updates/:up \
		SF/webadmin/${PORTNAME}/${PORTVERSION}:sf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sf \
		${WEBMIN_MODULES:S/gz$/gz:up/}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Web-based interface for system administration for Unix

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	p5-Authen-PAM>=0:security/p5-Authen-PAM \
		p5-IO-Tty>=0:devel/p5-IO-Tty \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay

USES=		cpe perl5 python shebangfix
USE_PYTHON=	py3kplist
USE_RC_SUBR=	webmin
SUB_LIST=	PERL=${PERL}
SUB_FILES=	pkg-message
SHEBANG_FILES=	${WRKSRC}/ajaxterm/ajaxterm/ajaxterm.py \
		${WRKSRC}/ajaxterm/ajaxterm/configure \
		${WRKSRC}/webmin/acme_tiny.py

WEBMIN_MODULES=

post-extract:
	@${RM} ${WRKSRC}/mount/freebsd-mounts-? \
		${WRKSRC}/webmin-gentoo-init
	@if [ "${WEBMIN_MODULES}" != "" ]; then \
		for webmin_module in ${WEBMIN_MODULES}; do \
			${ECHO} "===> Unpacking updated module: $${webmin_module}"; \
			${TAR} --unlink -xzf ${DISTDIR}/$${webmin_module} -C ${WRKSRC}; \
		done; \
	fi
	@${RM} -r -f ${WRKSRC}/acl/Authen-SolarisRBAC-0.1

post-patch:
	@${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@g" ${WRKSRC}/setup.sh

	@${FIND} ${WRKSRC} \( -type f -and \( -name config-freebsd\* -or -name config \) \) \
		-exec ${REINPLACE_CMD} -e "s@/usr/local@${PREFIX}@g" {} \; \
		-exec ${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@g" {} \;

	@${FIND} ${WRKSRC} \( -name "*.cgi" -or -name "*.pl" -or -name "*.sh" \) -exec \
		${REINPLACE_CMD} -e "s@%%PERL%%@${PERL}@g; s@#!/usr/bin/perl@#!${PERL}@; s@#!/usr/local/bin/perl@#!${PERL}@" {} \;

	@${FIND} ${WRKSRC} \( -name "*.orig" -or -name "*.bak" -or -name "*.pyc" \) -delete

	@${PRINTF} "g/^FreeBSD/m0\nwq\n" | ex ${WRKSRC}/os_list.txt

do-build:
	@${PYTHON_CMD} -mcompileall ${WRKSRC}/ajaxterm/ajaxterm/
	@${PYTHON_CMD} -O -mcompileall ${WRKSRC}/ajaxterm/ajaxterm/
	@${CC} ${CFLAGS} -o ${WRKSRC}/mount/freebsd-mounts-7 ${WRKSRC}/mount/freebsd-mounts-7.c
	@${STRIP_CMD} ${WRKSRC}/mount/freebsd-mounts-7

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/webmin
	${CP} -r ${WRKSRC}/* ${STAGEDIR}${PREFIX}/lib/webmin

.include <bsd.port.mk>
