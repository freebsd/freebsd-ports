# ports collection Makefile for: leafnode
# Whom:			Brian Somers <brian@FreeBSD.org>
# Date created:		1997-06-27
#
# $FreeBSD$
#

PORTNAME=	leafnode
PORTVERSION=	1.9.43
CATEGORIES=	news ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:sourceforge/} \
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

.if exists(/var/spool/news) && !defined(PACKAGE_BUILDING)
LEAFNODE_SPOOLDIR?=/var/spool/news
.endif
LEAFNODE_SPOOLDIR?=${PREFIX}/var/spool/leafnode
PLIST_SUB=	SPOOLDIR=${LEAFNODE_SPOOLDIR}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --sysconfdir=${PREFIX}/etc/leafnode \
		--with-lockfile=${LEAFNODE_SPOOLDIR}/leaf.node/lock.file \
		--with-spooldir=${LEAFNODE_SPOOLDIR} --with-ipv6
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS=
MAN1=		leafnode-version.1 newsq.1
MAN8=		applyfilter.8 checkgroups.8 fetchnews.8 leafnode.8 texpire.8
PKGMESSAGE=	${WRKSRC}/pkg-message

pre-configure:
		@${ECHO}
		@${ECHO} "------------------------------------------------------------------------"
		@${ECHO} "This port will use ${LEAFNODE_SPOOLDIR} as spool directory."
		@${ECHO} "Use LEAFNODE_SPOOLDIR=d to specify d as spool directory."
		@${ECHO} "------------------------------------------------------------------------"
		@${ECHO}

post-install:
		${INSTALL_PROGRAM} ${WRKSRC}/quickmkdir ${PREFIX}/sbin/
		${INSTALL_SCRIPT} ${WRKSRC}/setup-daemontools.sh ${PREFIX}/sbin/
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		for i in ChangeLog COPYING CREDITS FAQ.txt FAQ.pdf FAQ.html \
			 INSTALL NEWS README ChangeLog.old \
			 README-FQDN README-FQDN.html README-daemontools \
			 README.FIRST TODO leafnode.cron.daily \
			 leafnode-SA-2002-01 leafnode-SA-2003-01 \
			 KNOWNBUGS ; do \
		  ${INSTALL_MAN} ${WRKSRC}/$$i ${DOCSDIR} ; \
		done
		${MKDIR} ${DOCSDIR}/doc_german
		for i in INSTALL_de LIESMICH-daemontools README \
			README_de newsq.1 ${MAN8} ; do \
		  ${INSTALL_MAN} ${WRKSRC}/doc_german/$$i \
			${DOCSDIR}/doc_german ; done
.endif
		@${SED} 's:%%DOCSDIR%%:${DOCSDIR}:g' ${FILESDIR}/pkg-message.in >${PKGMESSAGE}
		${CAT} ${PKGMESSAGE}
		PKG_PREFIX=${PREFIX} SPOOLDIR=${LEAFNODE_SPOOLDIR} \
			${SH} pkg-install ${PORTNAME} POST-INSTALL

.include <bsd.port.mk>
