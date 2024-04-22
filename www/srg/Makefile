PORTNAME=	srg
PORTVERSION=	1.3.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://mirror.crc.net.nz/pub/srg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Squid Report Generator
WWW=		http://www.crc.net.nz/software/srg.php

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2
USE_CXXSTD=	c++14

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e \
		'/CPPFLAGS/s|-I/usr/local/include|| ; \
		 /LDFLAGS/s|-L/usr/local/lib||' ${WRKSRC}/configure

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for ex in srg.daily srg.monthly srg.weekly
	${INSTALL_DATA} ${WRKSRC}/examples/${ex} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
