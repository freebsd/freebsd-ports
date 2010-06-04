# New ports collection makefile for:    grep
# Date created:                         5 February 2010
# Whom:                                 Gabor Kovesdan <gabor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grep
PORTVERSION=	2.6.3
PORTREVISION=	2
CATEGORIES=     textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	gnu

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	GNU grep

USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
MAN1=		egrep.1 \
		fgrep.1 \
		grep.1
INFO=		grep
PLIST_FILES=    bin/egrep \
		bin/fgrep \
		bin/grep

OPTIONS=	PCRE	"Compile with Perl-compatible regex support"	off

CONFLICTS=	bsd-grep-*

USE_XZ=		yes

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--disable-nls

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
.else
CONFIGURE_ARGS+=	--disable-perl-regexp
.endif

post-patch:
	@${REINPLACE_CMD} 's|mkinstalldirs = .*|mkinstalldirs = mkdir -p|g' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.post.mk>
