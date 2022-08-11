PORTNAME=	leafnode
DISTVERSION=	1.12.0
CATEGORIES=	news
MASTER_SITES=	SF \
		LOCAL/mandree/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	NNTP package for offline news caching and reading

LICENSE=	GPLv2+

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		cpe tar:xz
GNU_CONFIGURE=	yes

CONFLICTS=	newsx-1* s-news-0*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

# TODO: remove this auto-selection, and tell users through UPDATING to
# move their spool to /var/spool/leafnode, and run texpire -r
.if exists(/var/spool/news/leaf.node) && !defined(PACKAGE_BUILDING)
LEAFNODE_SPOOLDIR?=	/var/spool/news
.elif exists(${LOCALBASE}/var/spool/leafnode/leaf.node) && !defined(PACKAGE_BUILDING)
LEAFNODE_SPOOLDIR?=	${LOCALBASE}/var/spool/leafnode
.endif
LEAFNODE_SPOOLDIR?=	/var/spool/leafnode
PLIST_SUB+=		REALPREFIX=${PREFIX} \
			SPOOLDIR=${LEAFNODE_SPOOLDIR}

CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--sysconfdir=${PREFIX}/etc/leafnode \
		--with-ipv6 \
		--with-spooldir=${LEAFNODE_SPOOLDIR}
SUB_FILES=	pkg-deinstall pkg-install pkg-message
SUB_LIST=	SPOOLDIR=${LEAFNODE_SPOOLDIR}
TEST_TARGET=	check

MAN1_DE=	leafnode-version.1 newsq.1
MAN8_DE=	applyfilter.8 checkgroups.8 fetchnews.8 leafnode.8 texpire.8
MANLANG=	"" de.ISO8859-1
MAN1DIR_DE=	${MAN1PREFIX}/man/de.ISO8859-1/man1
MAN8DIR_DE=	${MAN8PREFIX}/man/de.ISO8859-1/man8

DOCS=		ADD-ONS ChangeLog COPYING CREDITS FAQ.txt FAQ.pdf FAQ.html \
		INSTALL NEWS README ChangeLog.old README-FQDN README-FQDN.html \
		leafnode.cron.daily leafnode-SA-2002-01.txt \
		leafnode-SA-2003-01.txt leafnode-SA-2004-01.txt \
		leafnode-SA-2005-01.txt leafnode-SA-2005-02.txt KNOWNBUGS
DOCS_DE=	INSTALL_de README README_de

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

pre-configure:
	@${ECHO_MSG}
	@${ECHO_MSG} "------------------------------------------------------------------------"
	@${ECHO_MSG} "This port will use ${LEAFNODE_SPOOLDIR} as spool directory."
	@${ECHO_MSG} "Use LEAFNODE_SPOOLDIR=d to specify d as spool directory."
	@${ECHO_MSG} "------------------------------------------------------------------------"
	@${ECHO_MSG}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/UNINSTALL-daemontools ${STAGEDIR}${PREFIX}/etc/leafnode/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/german
	cd ${WRKSRC}/doc_german && ${INSTALL_DATA} ${DOCS_DE} ${STAGEDIR}${DOCSDIR}/german
.endif
	${MKDIR} ${STAGEDIR}${MAN1DIR_DE} ${STAGEDIR}${MAN8DIR_DE}
	cd ${WRKSRC}/doc_german && \
	${INSTALL_MAN} ${MAN1_DE} ${STAGEDIR}${MAN1PREFIX}/man/de.ISO8859-1/man1 && \
	${INSTALL_MAN} ${MAN8_DE} ${STAGEDIR}${MAN8PREFIX}/man/de.ISO8859-1/man8

.include <bsd.port.post.mk>
