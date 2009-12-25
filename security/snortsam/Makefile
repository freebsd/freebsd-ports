# New ports collection makefile for:	SnortSam
# Date created:        27 August 2008
# Whom:                Danton Dorati <urisso@bsd.com.br>
#
# $FreeBSD$
#

PORTNAME=	snortsam
PORTVERSION=	2.63
CATEGORIES=	security
MASTER_SITES=	http://www.snortsam.net/files/snortsam/ \
		http://www.freebsdbrasil.com.br/~urisso/files/snortsam/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	urisso@bsd.com.br
COMMENT=	SnortSam is a output plugin for Snort

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}

HAS_CONFIGURE=	yes
NO_BUILD=	yes

SYSCONFDIR=	${PREFIX}/etc/snortsam

CONFIGURE_SCRIPT=	makesnortsam.sh

USE_RC_SUBR=	snortsam.sh

PLIST_DIRS=	etc/snortsam
PLIST_FILES=	etc/snortsam/rootservers.cfg etc/snortsam/snortsam.conf.sample sbin/snortsam sbin/snortsam-debug
PORTDOCS=	INSTALL README README.conf README.snmp_interface_down

OPTIONS=	IPFW	"Enable IPFW table checking if it set deny rules" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_IPFW)
PATCH_SITES+=http://www.freebsdbrasil.com.br/~urisso/files/snortsam/:ipfw
PATCHFILES+=ssp_ipfw2.c.diff:ipfw
.endif

post-extract:
	@${CAT} ${PATCHDIR}/pkg-message-snortsam
	@sleep 5

pre-configure:
	${REINPLACE_CMD} -e 's|/etc/snortsam.conf|/usr/local/etc/snortsam.conf|g' ${WRKSRC}/conf/snortsam.conf.sample
	${REINPLACE_CMD} -e 's|/etc/snortsam.conf|/usr/local/etc/snortsam.conf|g' ${WRKSRC}/docs/README.conf
	${REINPLACE_CMD} -e 's|/etc/snortsam.conf|/usr/local/etc/snortsam.conf|g' ${WRKSRC}/src/snortsam.c
	${REINPLACE_CMD} -e 's|/etc/snortsam.conf|/usr/local/etc/snortsam.conf|g' ${WRKSRC}/contrib/snortsam-state.c
	${CHMOD} +x ${WRKSRC}/makesnortsam.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snortsam ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/snortsam-debug ${PREFIX}/sbin
	${MKDIR} ${SYSCONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/snortsam.conf.sample ${SYSCONFDIR}/snortsam.conf.sample
	${INSTALL_DATA} ${WRKSRC}/conf/*rootservers.cfg ${SYSCONFDIR}/

.if !defined(NOPORTDOCS)
.for f in ${PORTDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
