PORTNAME=	mew
DISTVERSIONPREFIX=	v
DISTVERSION=	6.10
DISTVERSIONSUFFIX=
CATEGORIES=	mail elisp
PKGNAMESUFFIX=	-devel${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Messaging in the Emacs World for emacs (Development Version)
WWW=		https://www.Mew.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	kazu-yamamoto
GH_PROJECT=	Mew

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-elispdir=${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/mew \
		--with-etcdir=${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/mew/etc

# target name for make build and install
ALL_TARGET=	all info jinfo
INSTALL_TARGET=	install install-jinfo

CONFLICTS_INSTALL=	mew mew-devel-emacs_* mew-emacs_* # bin/cmew bin/incm

SUB_FILES=	pkg-message

INFO=		mew mew.ja
PORTDOCS=	API.md CHANGES.v0.md CHANGES.v1.md CHANGES.v2.md CHANGES.v3.md \
		CHANGES.v4.1.md CHANGES.v4.2.md CHANGES.v5.1.md CHANGES.v5.2.md \
		CHANGES.v6.1.md CHANGES.v6.2.md CHANGES.v6.3.md CHANGES.v6.4.md \
		CHANGES.v6.5.md CHANGES.v6.6.md CHANGES.v6.7.md CHANGES.v6.8.md \
		CHANGES.v6.9.md INSTALL.md README.md RELEASENOTE.md

OPTIONS_DEFINE=		DATABASE DOCS STUNNEL
OPTIONS_DEFAULT=	STUNNEL

DATABASE_DESC=	Support database feature (with Ruby & Sqlite3)
STUNNEL_DESC=	Support TLS feature using stunnel

DATABASE_RUN_DEPENDS=	rubygem-sqlite3>=0:databases/rubygem-sqlite3
STUNNEL_RUN_DEPENDS=	stunnel>=0:security/stunnel

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${WRKSRC}/CHANGES/*.md ${STAGEDIR}${DOCSDIR}
	(cd ${STAGEDIR}${DOCSDIR}; for f in v*.md ; do ${MV} $$f CHANGES.$$f; done)

.include <bsd.port.mk>
