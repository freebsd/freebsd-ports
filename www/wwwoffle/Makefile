PORTNAME=	wwwoffle
PORTVERSION=	2.9j
CATEGORIES=	www
MASTER_SITES=	http://www.gedanken.org.uk/software/wwwoffle/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Caching proxy server for HTTP and FTP designed for dial-up hosts

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls

USES=		perl5 gmake tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc --with-ipv6 \
		--with-gnutls=${LOCALBASE} \
		--with-spooldir=${WWWOFFLE_SPOOL} \
		--docdir=${DOCSDIR}
LIBS+=		-lmd

PLIST_SUB+=	WWWOFFLE_SPOOL=${WWWOFFLE_SPOOL}
SUB_FILES=	pkg-message
SUB_LIST=	WWWOFFLE_SPOOL="${WWWOFFLE_SPOOL}"

USE_RC_SUBR=	${PORTNAME}d

# $SPOOL seems like a common name which could be used for other things, so
# use $WWWOFFLE_SPOOL as the overriding setting.
WWWOFFLE_SPOOL?=	/var/spool/wwwoffle

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/conf/upgrade-config.pl ${STAGEDIR}${WWWOFFLE_SPOOL}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}* ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}d

.include <bsd.port.mk>
