# New ports collection makefile for:	Net-uFTP
# Date created:				2010-11-10
# Whom:					Jase Thew <freebsd@beardz.net>
#
# $FreeBSD$
#

PORTNAME=	Net-uFTP
PORTVERSION=	0.16
CATEGORIES=	net devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd@beardz.net
COMMENT=	A universal interface for FTP-like modules (FTP, SFTP, SCP)

BUILD_DEPENDS=	p5-Class-Accessor-Fast-XS>=0:${PORTSDIR}/devel/p5-Class-Accessor-Fast-XS \
		p5-File-Stat-ModeString>=0:${PORTSDIR}/sysutils/p5-File-Stat-ModeString \
		p5-Net-FTP-AutoReconnect>=0:${PORTSDIR}/net/p5-Net-FTP-AutoReconnect \
		p5-Net-SSH2>=0:${PORTSDIR}/net/p5-Net-SSH2 \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::uFTP.3

.include <bsd.port.mk>
