# New ports collection makefile for:	blocksshd
# Date created:		2006-07-20
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	blocksshd
PORTVERSION=	1.0.1
CATEGORIES=	security sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	blocksshd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Protects computers from SSH brute force attacks

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS/Resolver.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/File/Tail.pm:${PORTSDIR}/devel/p5-File-Tail \
		${SITE_PERL}/Net/Subnets.pm:${PORTSDIR}/net/p5-Net-Subnets

MAKE_ARGS=	PREFIX="${PREFIX}" SYSCONFDIR="${PREFIX}/etc"
NO_BUILD=	yes
USE_PERL5_RUN=	yes

MAN1=		blocksshd.1

post-patch:
	@${CHMOD} 755 ${WRKSRC}/init
	@${REINPLACE_CMD} -e 's|^MANCOMPRESS = .gz||g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/etc/blocksshd.conf|${PREFIX}/etc/blocksshd.conf|g' ${WRKSRC}/blocksshd

.include <bsd.port.mk>
