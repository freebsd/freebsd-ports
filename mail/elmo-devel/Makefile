# Created by: trevor
# $FreeBSD$

PORTNAME=	elmo
PORTVERSION=	1.3.2
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Receive, filter, read, compose, and send mail at the text console

CONFLICTS=	elmo-[0-9]*

GNU_CONFIGURE=	yes
USES=		iconv ncurses perl5 shebangfix
SHEBANG_FILES=	src/elmoconf.pl
USE_OPENSSL=	yes
USE_PERL5=	run

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USES+=		gettext
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libgpgme.so) || defined(WITH_GPGME)
LIB_DEPENDS+=	libgpgme.so:security/gpgme
.else
pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "Define WITH_GPGME=yes to build with gpgme support."
	@${ECHO_CMD}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gpgme4|gpgme|g' -e 's|== "|= "|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|gpgme4|gpgme|g' ${WRKSRC}/src/pgp.c

.include <bsd.port.post.mk>
