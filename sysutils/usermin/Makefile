PORTNAME=	usermin
PORTVERSION=	2.400
CATEGORIES=	sysutils
MASTER_SITES=	http://www.webmin.com/uupdates/:up \
		SF/webadmin/${PORTNAME}/${PORTVERSION}:sf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sf \
		${USERMIN_MODULES:S/gz$/gz:up/}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Web-based interface for performing some user tasks
WWW=		http://www.usermin.com/

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	p5-Authen-PAM>=0:security/p5-Authen-PAM \
		p5-IO-Tty>=0:devel/p5-IO-Tty \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay

USES=		cpe perl5
CPE_VENDOR=	webmin
USE_RC_SUBR=	usermin
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PERL=${PERL}

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

	@${FIND} ${WRKSRC} \( -type f -and \( -name config-freebsd\* -or -name config \) \) \
		-exec ${REINPLACE_CMD} -e "s@/usr/local@${PREFIX}@g" {} \; \
		-exec ${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@g" {} \;

	@${FIND} ${WRKSRC} \( -name "*.cgi" -or -name "*.pl" -or -name "*.sh" \) -exec \
		${REINPLACE_CMD} -e "s@%%PERL%%@${PERL}@g; s@#!/usr/bin/perl@#!${PERL}@; s@#!/usr/local/bin/perl@#!${PERL}@" {} \;

	@${FIND} ${WRKSRC} \( -name "*.orig" -or -name "*.bak" -or -name "*.pyc" \) -delete

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/usermin
	${CP} -r ${WRKSRC}/* ${STAGEDIR}${PREFIX}/lib/usermin

.include <bsd.port.mk>
