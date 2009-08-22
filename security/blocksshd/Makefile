# New ports collection makefile for:	blocksshd
# Date created:		2006-07-20
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	blocksshd
PORTVERSION=	1.3
CATEGORIES=	security sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/BlockSSHD%20${PORTVERSION}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Protects computers from SSH brute force attacks

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS/Resolver.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/File/Tail.pm:${PORTSDIR}/devel/p5-File-Tail \
		${SITE_PERL}/Net/Subnets.pm:${PORTSDIR}/net/p5-Net-Subnets

MAKE_ARGS=	PREFIX="${PREFIX}" SYSCONFDIR="${PREFIX}/etc"
NO_BUILD=	yes
USE_PERL5_RUN=	yes
USE_RC_SUBR=	blocksshd
USE_DOS2UNIX=	blocksshd blocksshd.conf

MAN1=		blocksshd.1
MANCOMPRESSED=	yes

post-extract:
	@${CHMOD} 755 ${WRKSRC}/init

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/blocksshd.conf|${PREFIX}/etc/blocksshd.conf|g' ${WRKSRC}/blocksshd

post-install:
	@if [ ! -f ${PREFIX}/etc/blocksshd.conf ]; then \
		${CP} ${PREFIX}/etc/blocksshd.conf.sample ${PREFIX}/etc/blocksshd.conf; \
	fi

.include <bsd.port.mk>
