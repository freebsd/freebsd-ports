# New ports collection makefile for:	pine-pgp-filters
# Date created:				22 January 2003
# Whom:					dougb
#
# $FreeBSD$
#

PORTNAME=	pine-pgp-filters
PORTVERSION=	1.6
CATEGORIES=	mail security
MASTER_SITES=	http://dougbarton.us/PGP/scripts/ppf/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dougb
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	Simple /bin/sh-based filters to use GnuPG with Pine or Alpine

RUN_DEPENDS=	pine:${PORTSDIR}/mail/pine4

.include <bsd.port.pre.mk>

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
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} ${DOCSDIR}
.for file in BUGS CHANGES INSTALL LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
