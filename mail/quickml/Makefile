# Created by: Yuichiro AIZAWA <yaizawa@mdbl.sfc.keio.ac.jp>
# $FreeBSD$

PORTNAME=	quickml
PORTVERSION=	0.7
PORTREVISION=	13
CATEGORIES=	mail
MASTER_SITES=	http://0xcc.net/quickml/

MAINTAINER=	yaizawa@2004.jukuin.keio.ac.jp
COMMENT=	An easy-to-use mailing list system

LICENSE=	GPLv2

USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
USE_RUBY=	yes
USE_RC_SUBR=	${PORTNAME}

USERS=	quickml
GROUPS=	quickml

CONFIGURE_ARGS=	--datadir="${PREFIX}/share/quickml" \
	--with-ruby="${RUBY}" \
	--with-user="${USERS}" \
	--with-group="${GROUPS}" \
	--with-rubydir="${RUBY_LIBDIR}"

SUB_LIST=	RUBY=${RUBY}

OPTIONS_DEFINE=	ANALOG LIMIT DOCS
OPTIONS_DEFAULT=	ANALOG
ANALOG_DESC=	quickml-analog
LIMIT_DESC=	Creators and Members Limitation Patch

NO_STAGE=	yes
.include <bsd.port.pre.mk>

EXTRA_PATCHES+=		${PATCHDIR}/extra-patch-ruby19-*

.if ${PORT_OPTIONS:MANALOG}
USE_GHOSTSCRIPT_RUN=	yes
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot \
		convert:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	ANALOG=""
.else
PLIST_SUB+=	ANALOG="@comment "
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-woanalog-Makefile.in
.endif

.if ${PORT_OPTIONS:MLIMIT}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-limit-*
.endif

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/messages.ja ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ml-usage.en.rd ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/quickml.en.rd ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/quickml.ja.rd ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/with-mta.en.rd ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/with-mta.ja.rd ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
