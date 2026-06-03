PORTNAME=	starttls
PORTVERSION=	0.10
PORTREVISION=	37
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.opaopa.org/pub/elisp/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Simple wrapper program for STARTTLS on Emacs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs gmake ssl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE}

MAKE_ARGS+=	lispdir=${PREFIX}/${EMACS_SITE_LISPDIR}

CONFLICTS_INSTALL=	starttls-emacs_*

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=       -Wno-error=int-conversion
.endif

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/starttls.elc

.include <bsd.port.post.mk>
