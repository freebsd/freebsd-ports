# $FreeBSD$

PORTNAME=	pine-pgp-filters
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	mail security
MASTER_SITES=	LOCAL/marino
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple /bin/sh-based filters to use GnuPG with Alpine

BUILD_DEPENDS=	gpg2:security/gnupg
RUN_DEPENDS+=	gpg2:security/gnupg
RUN_DEPENDS=	alpine:mail/alpine

PORTDOCS=	BUGS CHANGES INSTALL LICENSE README
PLIST_FILES=	bin/ppf_mime bin/ppf_mime_decrypt \
		libexec/ppf_decrypt libexec/ppf_encrypt libexec/ppf_mime \
		libexec/ppf_mime_decrypt libexec/ppf_sign libexec/ppf_verify

verify:	checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

do-configure:
	@(cd ${WRKSRC} && ./configure --prefix=${PREFIX})

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
