# New ports collection makefile for:	syslog-ng
# Date created:		22 April 2000
# Whom:			Vince Valenti <vince@blue-box.net>
#
# $FreeBSD$
#

PORTNAME=	syslog-ng
PORTVERSION=	1.6.12
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/sources/1.6/src/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	A powerful syslogd replacement

GNU_CONFIGURE=	yes
PKGMESSAGE=	${WRKDIR}/MESSAGE
USE_RC_SUBR=	syslog-ng.sh

OPTIONS=	TCP_WRAPPERS "Enable TCP wrapper support" off \
		SPOOF_SOURCE "Enable spoof-source support" off

SUB_FILES=	pkg-message

MAN5=		syslog-ng.conf.5
MAN8=		syslog-ng.8

.include <bsd.port.pre.mk>

.if defined(WITH_TCP_WRAPPERS)
CONFIGURE_ARGS+=	--enable-tcp-wrapper
.endif

.if defined(WITH_SPOOF_SOURCE)
LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config
CONFIGURE_ENV=	CFLAGS="`${LIBNET_CONFIG} --cflags`" \
		CPPFLAGS="`${LIBNET_CONFIG} --defines`" \
		LDFLAGS="`${LIBNET_CONFIG} --libs`"
CONFIGURE_ARGS+=	--enable-spoof-source
BUILD_DEPENDS+=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet
.endif

post-patch:
	@${REINPLACE_CMD} -e 's:libnet-config:libnet11-config:g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} \
		${DOCSDIR} ${DOCSDIR}/sgml
.for f in AUTHORS COPYING ChangeLog INSTALL NEWS PORTS README README.spoof
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/sgml/${PORTNAME}.* ${DOCSDIR}/sgml
.endif
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} ${PREFIX}/etc/syslog-ng
	${INSTALL_DATA} ${FILESDIR}/syslog-ng.conf.sample \
		${PREFIX}/etc/syslog-ng
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
