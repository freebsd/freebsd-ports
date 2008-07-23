# New ports collection makefile for:	nfsen-devel
# Date created:		21 May 2007
# Whom:			janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	nfsen
DISTVERSION=	20070312
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF
PKGNAMESUFFIX=	-devel
DISTNAME=	nfsen-snapshot-${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Development version of web based frontend to nfdump

RUN_DEPENDS=	nfdump:${PORTSDIR}/net-mgmt/nfdump \
		${SITE_PERL}/Mail/Header.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/RRDp.pm:${PORTSDIR}/databases/rrdtool

BROKEN=		fails to install

CONFLICTS=	nfsen-[0-9]*

USE_ICONV=	yes
USE_PERL5=	yes
USE_PHP=	session pcre sockets
NO_BUILD=	yes
PLIST_SUB+=	PORTNAME=${PORTNAME}
USE_RC_SUBR=	nfsen.sh

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "*****************************************************"
	@${ECHO_MSG} "Before upgrading you may backup the original profile "
	@${ECHO_MSG} "stat data:"
	@${ECHO_MSG} "cd ${WRKSRC}/helpers"
	@${ECHO_MSG} "./mk_backup.sh /path/to/your/profilestatdir /path/to/backupdir"
	@${ECHO_MSG} "*****************************************************"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' -e 's,%%PORTNAME%%,${PORTNAME},' \
		${WRKSRC}/etc/nfsen-dist.conf
	@${RM} ${WRKSRC}/etc/nfsen-dist.conf.*
	@${RM} ${WRKSRC}/bin/testPlugin.orig
	@${REINPLACE_CMD} -e 's,%%PERL%%,${PERL},' -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/install.pl

do-install:
	@${MKDIR} ${PREFIX}/var/${PORTNAME}/profiles/live
	@${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/installer-items/CopyRecursive.pm ${PREFIX}/libexec/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/installer-items/RRDconvertv1.pm ${PREFIX}/libexec/${PORTNAME}/
	@ if [ -f ${PREFIX}/etc/nfsen.conf ] ; then \
	${ECHO_MSG} "installing with existing nfsen.conf"; \
	cd ${WRKSRC} ;${PERL} ${WRKSRC}/install.pl ${PREFIX}/etc/nfsen.conf; \
	else \
	${ECHO_MSG} "installing with sample nfsen.conf"; \
	cd ${WRKSRC} ;${PERL} ${WRKSRC}/install.pl ${WRKSRC}/etc/nfsen-dist.conf; \
	fi
	@${ECHO_MSG} "Configure your ${LOCALBASE}/etc/nfsen.conf to have necessary sources ";
	@${ECHO_MSG} "Then run 'nfsen reconfig' to correctly setup source, RRD, and profile files";

.include <bsd.port.mk>
