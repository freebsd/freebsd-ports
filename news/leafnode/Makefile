# ports collection Makefile for: leafnode
# Whom:			Brian Somers <brian@FreeBSD.org>
# Date created:		1997-06-27
#
# $FreeBSD$
#

PORTNAME=	leafnode
PORTVERSION=	1.11.3
CATEGORIES=	news ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED:S/$/:sourceforge/} \
		http://osdn.dl.sourceforge.net/sourceforge/${PORTNAME}/:sourceforge \
		http://www.dt.e-technik.uni-dortmund.de/~ma/${PORTNAME}/ \
		${MASTER_SITE_SUNSITE:S/$/:sunsite/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:sourceforge \
			./:DEFAULT \
			system/news/transport/:sunsite
DISTNAME=	${PORTNAME}-${PORTVERSION}.rel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sourceforge,sunsite,DEFAULT

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	NNTP package for offline news caching and reading

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if exists(/var/spool/news/leaf.node) && !defined(PACKAGE_BUILDING)
LEAFNODE_SPOOLDIR?=/var/spool/news
.elif exists(${LOCALBASE}/var/spool/leafnode/leaf.node) && !defined(PACKAGE_BUILDING)
LEAFNODE_SPOOLDIR?=${LOCALBASE}/var/spool/leafnode
.endif
LEAFNODE_SPOOLDIR?=/var/spool/leafnode
PLIST_SUB=	SPOOLDIR=${LEAFNODE_SPOOLDIR}

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/leafnode \
		--with-spooldir=${LEAFNODE_SPOOLDIR} --with-ipv6
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
SUB_FILES=	pkg-message pkg-install
SUB_LIST=	SPOOLDIR=${LEAFNODE_SPOOLDIR}

MAN1=		leafnode-version.1 newsq.1
MAN8=		applyfilter.8 checkgroups.8 fetchnews.8 leafnode.8 texpire.8
MANLANG=	"" de.ISO8859-1
MAN1DIR_DE=	${MAN1PREFIX}/man/de.ISO8859-1/man1
MAN8DIR_DE=	${MAN8PREFIX}/man/de.ISO8859-1/man8

DOCS=		ADD-ONS ChangeLog COPYING CREDITS FAQ.txt FAQ.pdf FAQ.html \
		INSTALL NEWS README ChangeLog.old README-FQDN README-FQDN.html \
		README-daemontools README.FIRST leafnode.cron.daily \
		leafnode-SA-2002-01.txt leafnode-SA-2003-01.txt \
		leafnode-SA-2004-01.txt \
		leafnode-SA-2005-01.txt \
		leafnode-SA-2005-02.txt \
		KNOWNBUGS
DOCS_DE=	INSTALL_de LIESMICH-daemontools README README_de

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "------------------------------------------------------------------------"
	@${ECHO_MSG} "This port will use ${LEAFNODE_SPOOLDIR} as spool directory."
	@${ECHO_MSG} "Use LEAFNODE_SPOOLDIR=d to specify d as spool directory."
	@${ECHO_MSG} "------------------------------------------------------------------------"
	@${ECHO_MSG}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/setup-daemontools.sh ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/german
	cd ${WRKSRC}/doc_german && ${INSTALL_DATA} ${DOCS_DE} ${DOCSDIR}/german
.endif
	${MKDIR} ${MAN1DIR_DE} ${MAN8DIR_DE}
	cd ${WRKSRC}/doc_german && \
	${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/de.ISO8859-1/man1 && \
	${INSTALL_MAN} ${MAN8} ${MAN8PREFIX}/man/de.ISO8859-1/man8
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
