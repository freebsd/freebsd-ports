# New ports collection makefile for:	p5-File-Rsync
# Date created:				20 May 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	File-Rsync
PORTVERSION=	0.42
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl convenience wrapper for the rsync(1) program

BUILD_DEPENDS=	rsync:${PORTSDIR}/net/rsync
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	</dev/null

MAN3=		File::Rsync.3

post-patch:
		@${REINPLACE_CMD} -e "s,<STDIN>,'${LOCALBASE}/bin/rsync'," ${WRKSRC}/makepm.PL

.include <bsd.port.mk>
