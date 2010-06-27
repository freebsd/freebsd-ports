# New ports collection Makefile for:	libgcrypt
# Date created:				July 17 2002
# Whom:					Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libgcrypt
PORTVERSION=	1.4.5
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	General purpose crypto library based on code used in GnuPG

LIB_DEPENDS=	gpg-error.0:${PORTSDIR}/security/libgpg-error

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
USE_LDCONFIG=	yes

DOCS=	AUTHORS COPYING COPYING.LIB ChangeLog INSTALL NEWS README README.SVN \
	THANKS TODO doc/HACKING doc/README.apichanges
INFO=	gcrypt

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
CONFIGURE_ARGS+=	--disable-asm
.endif
.if (${OSVERSION} < 700000)
CONFIGURE_ARGS+=	--disable-padlock-support
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|" \
		${WRKSRC}/ltmain.sh

pre-configure:
	@${RM} -f ${WRKSRC}/doc/gcrypt.info*

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
