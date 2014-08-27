# $FreeBSD$

PORTNAME=	pine-pgp-filters
PORTVERSION=	1.8
CATEGORIES=	mail security
#MASTER_SITES=
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple /bin/sh-based filters to use GnuPG with Alpine

RUN_DEPENDS=	alpine:${PORTSDIR}/mail/alpine

PORTDOCS=	BUGS CHANGES INSTALL LICENSE README
PLIST_FILES=	bin/ppf_mime bin/ppf_mime_decrypt \
		libexec/ppf_decrypt libexec/ppf_encrypt libexec/ppf_mime \
		libexec/ppf_mime_decrypt libexec/ppf_sign libexec/ppf_verify

# We want to be version-agnostic here, but also record the right dependency
# if the user installs the package and already has one or the other installed.
.if exists(${LOCALBASE}/bin/gpg2)
BUILD_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg
RUN_DEPENDS+=	gpg2:${PORTSDIR}/security/gnupg
.else
BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg1
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg1
.endif

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
