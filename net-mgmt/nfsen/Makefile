# New ports collection makefile for:	nfsen
# Date created:		25 March 2005
# Whom:			janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	nfsen
PORTVERSION=	1.2.4.20060810
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://nfsen.sourceforge.net/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-snapshot-20060810

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Web based frontend to nfdump netflow collector

RUN_DEPENDS=	${SITE_PERL}/RRDp.pm:${PORTSDIR}/databases/rrdtool \
		nfdump:${PORTSDIR}/net-mgmt/nfdump

USE_ICONV=	yes
USE_PERL5=	yes
USE_PHP=	session pcre sockets
NO_BUILD=	yes
PLIST_SUB+=	PORTNAME=${PORTNAME}
USE_RC_SUBR=	nfsen.sh

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires at least perl 5.6.0
.endif

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
	@${ECHO_MSG} "Then run 'nfsen -R ${LOCALBASE}/etc/nfsen.conf' to correctly setup source, RRD, and profile files";

.include <bsd.port.post.mk>
