# New ports collection makefile for:	usermin
# Date created:		10 Nov 2002
# Whom:			olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	usermin
PORTVERSION=	1.410
CATEGORIES=	sysutils
MASTER_SITES=	http://www.webmin.com/uupdates/:up \
		SF/webadmin/${PORTNAME}/${PORTVERSION}:sf \
		${MASTER_SITE_LOCAL:S/$/:up/}
MASTER_SITE_SUBDIR=	olgeni/:up
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sf ${USERMIN_MODULES:S/gz$/gz:up/}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Web-based interface for performing some user tasks

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/${PERL_ARCH}/Authen/PAM.pm:${PORTSDIR}/security/p5-Authen-PAM

FETCH_CMD?=	/usr/bin/fetch -pRr
NO_BUILD=	yes
USE_PERL5=	yes
USE_RC_SUBR=	usermin.sh
SUB_LIST=	PERL5=${PERL}

USERMIN_MODULES=

post-extract:
	@if [ "${USERMIN_MODULES}" != "" ]; then \
		for usermin_module in ${USERMIN_MODULES}; do \
			${ECHO} "===> Unpacking updated module: $${usermin_module}"; \
			${TAR} --unlink -xzf ${DISTDIR}/$${usermin_module} -C ${WRKSRC}; \
		done; \
	fi

post-patch:
.for file in	mysql/config-freebsd postgresql/config-freebsd \
		spam/config-freebsd
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e "s=%%PREFIX%%=${PREFIX}=" ${WRKSRC}/setup.sh
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
	@${MKDIR} ${PREFIX}/lib/usermin
	@${CP} -r ${WRKSRC}/* ${PREFIX}/lib/usermin

post-install:
	@cd ${WRKSRC} ; ${FIND} * -type f -o -type l | ${SORT} | ${AWK} \
		'{ print "lib/usermin/" $$1 }' > ${WRKDIR}/PLIST.lib-usermin
	@cd ${WRKSRC} ; ${FIND} * -type d -empty | ${SORT} -r | ${AWK} \
		'{ print "lib/usermin/" $$1 }' | ${SED} -e 's#^#@exec mkdir -p %D/#g' \
		>> ${WRKDIR}/PLIST.lib-usermin
	@cd ${WRKSRC} ; ${FIND} * -type d | ${SORT} -r | ${AWK} \
		'{ print "lib/usermin/" $$1 }' | ${SED} -e 's/^/@dirrm /g' \
		>> ${WRKDIR}/PLIST.lib-usermin
	@${ECHO_CMD} "r ${TMPPLIST}"			> ${WRKDIR}/ex.script
	@${ECHO_CMD} "/Insert PLIST.lib-usermin"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "d"				>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "r ${WRKDIR}/PLIST.lib-usermin"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "x!"				>> ${WRKDIR}/ex.script
	@${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-lib-usermin
	@cd ${WRKDIR} ; ex < ex.script
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
