# New ports collection makefile for:	p5-Net-ARP
# Date created:		2006-11-01
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-ARP
PORTVERSION=	1.0.2
CATEGORIES=	net
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension for creating ARP packets

PERL_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN3=	Net::ARP.3

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		Does not compile on amd64
.endif

.include <bsd.port.post.mk>
