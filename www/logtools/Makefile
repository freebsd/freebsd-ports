# Created by: Mark Huizer; Eindhoven
# $FreeBSD$

PORTNAME=	logtools
PORTVERSION=	0.13e
CATEGORIES=	www
MASTER_SITES=	http://www.coker.com.au/logtools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Useful tools to deal with CLF files (Common Log File format)

LICENSE=	GPLv2

BROKEN_powerpc64=	fails to compile: clfmerge.cpp: error: unordered_map: No such file or directory

USES=		tar:tgz
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O2 -g|| ; \
		 s|-lstdc++|| ; \
		 s| \($${prefix}\)| $${DESTDIR}\1|g ; \
		 s| \(@mandir@\)| $${DESTDIR}\1|g ; \
		 s|.cfg |.cfg.sample | ; \
		 s| \(@sysconfdir@\)| $${DESTDIR}\1|g' ${WRKSRC}/Makefile.in

post-build:
	@${LN} -sf clfdomainsplit.cfg ${WRKSRC}/clfdomainsplit.cfg.sample

.include <bsd.port.mk>
