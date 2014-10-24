# Created by: Dominic Marks <dominic.marks@btinternet.com>
# $FreeBSD$

PORTNAME=	honeyd
PORTVERSION=	1.5c
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	http://www.honeyd.org/uploads/ \
		http://www.citi.umich.edu/u/provos/honeyd/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Simulate virtual network hosts (honeypots)

LICENSE=	GPLv2

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2 \
		libdnet.so:${PORTSDIR}/net/libdnet \
		libpcre.so:${PORTSDIR}/devel/pcre

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libdnet=${LOCALBASE} \
		--with-libevent=${LOCALBASE}

EXTRA_PATCHES=	${FILESDIR}/honeyd-1.5c-libevent2.patch:-p1

.if defined(WITH_PYTHON)
USES+=			python
CONFIGURE_ARGS+=	--with-python
.else
CONFIGURE_ARGS+=	--without-python
.endif

.include <bsd.port.pre.mk>

.if !defined(WITH_PYTHON)
pre-everything::
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> You can enable Python support by defining the following variable:"
	@${ECHO_MSG} "===> WITH_PYTHON=yes   Enable Python support"
	@${ECHO_MSG} "===>"
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|LIBS = |LIBS = ${PTHREAD_LIBS}|' \
		${WRKSRC}/Makefile

# Have to make this directory, the Makefile is stupid and tries to
# install stuff here without making it.
pre-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/webserver

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/scripts/snmp
	@cd ${WRKSRC}/scripts && \
		${INSTALL_DATA} README* INSTALL* kuang2.conf \
			${STAGEDIR}${DATADIR}/scripts && \
		${INSTALL_SCRIPT} *.pl *.sh ${STAGEDIR}${DATADIR}/scripts
	@cd ${WRKSRC}/scripts/snmp && \
		${INSTALL_DATA} README default.snmp *.tpl \
			${STAGEDIR}${DATADIR}/scripts/snmp && \
		${INSTALL_SCRIPT} *.pl ${STAGEDIR}${DATADIR}/scripts/snmp

.include <bsd.port.post.mk>
