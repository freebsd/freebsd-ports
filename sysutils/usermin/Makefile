# $FreeBSD$

PORTNAME=	usermin
PORTVERSION=	1.590
CATEGORIES=	sysutils
MASTER_SITES=	http://www.webmin.com/uupdates/:up \
		SF/webadmin/${PORTNAME}/${PORTVERSION}:sf \
		${MASTER_SITE_LOCAL:S/$/:up/}
MASTER_SITE_SUBDIR=	olgeni/:up
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sf ${USERMIN_MODULES:S/gz$/gz:up/}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Web-based interface for performing some user tasks

RUN_DEPENDS=	p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-IO-Tty>=0:${PORTSDIR}/devel/p5-IO-Tty \
		p5-Authen-PAM>=0:${PORTSDIR}/security/p5-Authen-PAM

NO_BUILD=	yes
USES=		perl5
USE_RC_SUBR=	usermin
SUB_LIST=	PERL5=${PERL}
SUB_FILES=	pkg-message

USERMIN_MODULES=

post-extract:
	@if [ "${USERMIN_MODULES}" != "" ]; then \
		for usermin_module in ${USERMIN_MODULES}; do \
			${ECHO} "===> Unpacking updated module: $${usermin_module}"; \
			${TAR} --unlink -xzf ${DISTDIR}/$${usermin_module} -C ${WRKSRC}; \
		done; \
	fi

post-patch:
	@${REINPLACE_CMD} -e "s=%%PREFIX%%=${PREFIX}=" ${WRKSRC}/setup.sh

.for file in filter/config commands/config htaccess/config
	@${REINPLACE_CMD} -i '' -e 's|=/etc/webmin|=${PREFIX}/etc/webmin|' ${WRKSRC}/${file}
.endfor

	@${FIND} ${WRKSRC} -name config-freebsd\* \
		-exec ${REINPLACE_CMD} -e "s@/usr/local@${PREFIX}@g" {} \; \
		-exec ${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@g" {} \;

	@${FIND} ${WRKSRC} -name "*.cgi" -print \
		| ${XARGS} ${REINPLACE_CMD} -e "s@#!/usr/local/bin/perl@#!${PERL}@"
	@${FIND} ${WRKSRC} -name "*.cgi" -print \
		| ${XARGS} ${REINPLACE_CMD} -e "s@#!/usr/bin/perl@#!${PERL}@"
	@${FIND} ${WRKSRC} -name "*.pl" -print \
		| ${XARGS} ${REINPLACE_CMD} -e "s@#!/usr/local/bin/perl@#!${PERL}@"
	@${FIND} ${WRKSRC} -name "*.pl" -print \
		| ${XARGS} ${REINPLACE_CMD} -e "s@#!/usr/bin/perl@#!${PERL}@"

	@${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM}
	@${FIND} ${WRKSRC} -name "*.bak" -print | ${XARGS} ${RM}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/usermin
	${CP} -r ${WRKSRC}/* ${STAGEDIR}${PREFIX}/lib/usermin

.include <bsd.port.mk>
