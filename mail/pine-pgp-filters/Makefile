# New ports collection makefile for:	pine-pgp-filters
# Date created:				22 January 2003
# Whom:					dougb
#
# $FreeBSD$
#

PORTNAME=	pine-pgp-filters
PORTVERSION=	1.7
CATEGORIES=	mail security
MASTER_SITES=	http://dougbarton.us/PGP/ppf/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dougb
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	Simple /bin/sh-based filters to use GnuPG with Alpine

LICENSE=	BSD

PLIST_FILES=	bin/ppf_mime bin/ppf_mime_decrypt \
		libexec/ppf_decrypt libexec/ppf_encrypt libexec/ppf_mime \
		libexec/ppf_mime_decrypt libexec/ppf_sign libexec/ppf_verify

.include <bsd.port.pre.mk>

RUN_DEPENDS=	alpine:${PORTSDIR}/mail/alpine

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

PORTDOCS=	BUGS CHANGES INSTALL LICENSE README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
