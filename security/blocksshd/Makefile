# New ports collection makefile for:	blocksshd
# Date created:		2006-07-20
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	blocksshd
PORTVERSION=	0.9
CATEGORIES=	security sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	blocksshd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Protects computers from SSH brute force attacks

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS/Resolver.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/File/Tail.pm:${PORTSDIR}/devel/p5-File-Tail \
		${SITE_PERL}/Proc/Daemon.pm:${PORTSDIR}/devel/p5-Proc-Daemon \
		${SITE_PERL}/Proc/PID/File.pm:${PORTSDIR}/devel/p5-Proc-PID-File

MAKE_ARGS=	PREFIX="${TARGETDIR}"
NO_BUILD=	yes
USE_PERL5_RUN=	yes

MAN1=		blocksshd.1

post-patch:
	@${CHMOD} 755 ${WRKSRC}/init
	@${REINPLACE_CMD} -e 's|^MANCOMPRESS = .gz||g' ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/blocksshd.conf ${TARGETDIR}/etc

.include <bsd.port.mk>
