# New ports collection makefile for:    spamprobe
# Whom:                                 Matthew N. Dodd <mdodd@FreeBSD.org>
# Date created:                         05 September 2002
#
# $FreeBSD$
#

PORTNAME=	spamprobe
PORTVERSION=	1.4b
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	Spam detector using Bayesian analysis of word counts

LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-default-8bit --enable-cdb
CPPFLAGS=	-I${LOCALBASE}/include/db4
LDFLAGS=	-L${LOCALBASE}/lib -ldb4

MAN1=		spamprobe.1
PLIST_FILES=	bin/spamprobe

OPTIONS=	UNGIF "Enable tokenization of GIF attachments with libungif" off

.include <bsd.port.pre.mk>

.if defined(WITH_UNGIF)
LIB_DEPENDS+=	ungif.5:${PORTSDIR}/graphics/libungif
CPPFLAGS+=	-I${LOCALBASE}/include
.endif

.include <bsd.port.post.mk>
