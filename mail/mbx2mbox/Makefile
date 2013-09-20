# Created by: Josh Gilliam <josh@quick.net>
# $FreeBSD$

PORTNAME=	mbx2mbox
PORTVERSION=	0.34
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MS Outlook Express .mbx to mbox file converter

BUILD_DEPENDS=	p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=	mbx2mbox.1

NO_STAGE=	yes
.include <bsd.port.mk>
