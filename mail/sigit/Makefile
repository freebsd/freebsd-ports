# Created by: petef
# $FreeBSD$

PORTNAME=	sigit
PORTVERSION=	0.3.0
CATEGORIES=	mail
MASTER_SITES=	http://www.redhead.dk/download/stable/
DISTNAME=	Sigit-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to create random signatures

BUILD_DEPENDS=	${LOCALBASE}/bin/boxes:${PORTSDIR}/misc/boxes

LICENSE=	GPLv2

USES=		perl5
USE_PERL5=	build
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${DATADIR} \
		--bin-dir=${PREFIX}/bin \
		--man-dir=${PREFIX}/man \
		--etc-dir=${PREFIX}/etc

MAN1=	sigit.1 sigitdb.1
MAN5=	sigit.rc.5

NO_STAGE=	yes
post-patch:
	@${MV} ${WRKSRC}/data/sigit.rc ${WRKSRC}/data/sigit.rc.dist

post-install:
	@(if [ ! -f ${PREFIX}/etc/sigit.rc ]; then \
		${CP} ${PREFIX}/etc/sigit.rc.dist ${PREFIX}/etc/sigit.rc; fi)

.include <bsd.port.mk>
