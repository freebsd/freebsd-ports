# New ports collection makefile for:	p5-NetApp
# Date created:		2009-01-31
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	NetApp
PORTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	NetApp
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Perl interface to manage NetApp NAS devices

RUN_DEPENDS=	p5-IPC-Cmd>=0:${PORTSDIR}/devel/p5-IPC-Cmd \
		p5-Class-Std>=0:${PORTSDIR}/devel/p5-Class-Std \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Net-Telnet>=0:${PORTSDIR}/net/p5-Net-Telnet \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Clone>=0:${PORTSDIR}/devel/p5-Clone
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=		NetApp::Aggregate.3 \
		NetApp::Aggregate::Plex.3 \
		NetApp::Aggregate::RAIDGroup.3 \
		NetApp::Filer.3 \
		NetApp::Filer::Export.3 \
		NetApp::Filer::License.3 \
		NetApp::Filer::Option.3 \
		NetApp::Filer::Version.3 \
		NetApp::Qtree.3 \
		NetApp::Snapmirror.3 \
		NetApp::Snapshot.3 \
		NetApp::Snapshot::Delta.3 \
		NetApp::Snapshot::Schedule.3 \
		NetApp::Volume.3

.include <bsd.port.mk>
