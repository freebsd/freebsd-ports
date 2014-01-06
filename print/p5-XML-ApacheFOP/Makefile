# Created by: Simun Mikecin <numisemis@yahoo.com>
# $FreeBSD$

PORTNAME=	XML-ApacheFOP
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Access Apache FOP from Perl to create PDF files using XSL-FO

BUILD_DEPENDS=	p5-Java>=0:${PORTSDIR}/devel/p5-Java \
		${LOCALBASE}/share/java/fop/build/fop.jar:${PORTSDIR}/textproc/fop
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
