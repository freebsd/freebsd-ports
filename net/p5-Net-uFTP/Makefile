# Created by: Jase Thew <freebsd@beardz.net>
# $FreeBSD$

PORTNAME=	Net-uFTP
PORTVERSION=	0.161
PORTREVISION=	1
CATEGORIES=	net devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:STRZELEC
PKGNAMEPREFIX=	p5-

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Universal interface for FTP-like modules (FTP, SFTP, SCP)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor-Fast-XS>=0:devel/p5-Class-Accessor-Fast-XS \
		p5-File-Stat-ModeString>=0:sysutils/p5-File-Stat-ModeString \
		p5-Net-FTP-AutoReconnect>=0:net/p5-Net-FTP-AutoReconnect \
		p5-Net-SSH2>=0:net/p5-Net-SSH2 \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
