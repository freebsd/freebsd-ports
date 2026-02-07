PORTNAME=	qadsl
PORTVERSION=	1.3.3
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	SAVANNAH/alive

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Auto login/Keep-alive for Telia AB ADSL, COMHEM Cable, and Tiscali Internet
WWW=		https://www.gnu.org/software/alive/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_RC_SUBR=	qadsl
SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-global-cfg=${PREFIX}/etc/qadsl.conf \
		--with-pidfile=/var/run/qadsl.pid

INFO=		qadsl
PLIST_FILES=	sbin/qadsl etc/qadsl.conf.sample \
		share/man/man5/qadsl.conf.5.gz \
		share/man/man8/qadsl.8.gz

post-extract:
	@${CP} ${WRKSRC}/etc/qadsl.conf ${WRKSRC}/etc/qadsl.conf.sample

post-patch:
	@${REINPLACE_CMD} -e \
		'/echo $${CFLAGS}/s|^|#| ; \
		 /echo $${CXXFLAGS}/s|^|#| ; \
		 s|$$OPTIMIZER_CFLAGS||' ${WRKSRC}/configure

.include <bsd.port.mk>
