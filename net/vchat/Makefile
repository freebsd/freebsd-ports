# Created by: Andreas Wetzel <mickey@netassembly.de>
# $FreeBSD$

PORTNAME=	vchat
PORTVERSION=	2.42c
CATEGORIES=	net
MASTER_SITES=	http://www.enforcer.cc/vchat/filez/

MAINTAINER=	mickey@netassembly.de
COMMENT=	Client software for taking part in VChat conferences

GNU_CONFIGURE=	yes

MAN1=		vchat.1
MAN5=		vchatrc.5
MAN8=		vchatd.8

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_FILES=	bin/vchat libexec/vchatd

NO_STAGE=	yes
.include <bsd.port.mk>
