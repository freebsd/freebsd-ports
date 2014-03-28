# $FreeBSD$

PORTNAME=	wwwoffle
PORTVERSION=	2.9i
PORTREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.gedanken.org.uk/software/wwwoffle/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Caching proxy server for HTTP and FTP designed for dial-up hosts

LICENSE=	GPLv2

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls

USES=		perl5 gmake

USE_RC_SUBR=	${PORTNAME}d

# $SPOOL seems like a common name which could be used for other things, so
# use $WWWOFFLE_SPOOL as the overriding setting.
WWWOFFLE_SPOOL?=	/var/spool/wwwoffle

PLIST_SUB+=	WWWOFFLE_SPOOL=${WWWOFFLE_SPOOL}

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS=-lmd
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc --with-ipv6 \
		--with-gnutls=${LOCALBASE} \
		--with-spooldir=${WWWOFFLE_SPOOL} \
		--docdir=${DOCSDIR} \
		--mandir=${MANPREFIX}/man

SUB_FILES=	pkg-message
SUB_LIST=	WWWOFFLE_SPOOL="${WWWOFFLE_SPOOL}"

MAN1=		wwwoffle.1
MAN5=		wwwoffle.conf.5
MAN8=		wwwoffled.8

NO_STAGE=	yes
post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/conf/upgrade-config.pl ${WWWOFFLE_SPOOL}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
