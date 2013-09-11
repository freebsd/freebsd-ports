# Created by: LEVAI Daniel <leva@ecentrum.hu>
# $FreeBSD$

PORTNAME=	kc
PORTVERSION=	2.3.0
CATEGORIES=	security
MASTER_SITES=	http://keychain.googlecode.com/files/

MAINTAINER=	leva@ecentrum.hu
COMMENT=	Console based password storing application

LICENSE=	BSD

USES=		pkgconfig
LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		pcre:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser

MAN1=		kc.1
MANCOMPRESSED=	yes

PLIST_DIRS=	share/kc
PLIST_FILES=	bin/kc \
		share/kc/pwsafe_to_kc.pl

MAKE_ENV+=	HAVE_PCRE=yes

post-install:
	${INSTALL} -d ${PREFIX}/share/kc
	${INSTALL} ${WRKSRC}/pwsafe_to_kc.pl ${PREFIX}/share/kc/

.include <bsd.port.mk>
