# Created by: Dominic Marks <dominic.marks@btinternet.com>
# $FreeBSD$

PORTNAME=	honeyd
PORTVERSION=	1.5c
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.honeyd.org/uploads/ \
		http://www.citi.umich.edu/u/provos/honeyd/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Simulate virtual network hosts (honeypots)

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent \
		dnet.1:${PORTSDIR}/net/libdnet
BUILD_DEPENDS=	${LOCALBASE}/lib/libpcre.a:${PORTSDIR}/devel/pcre

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-libdnet=${LOCALBASE} \
		--with-libevent=${LOCALBASE}

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--with-python
.else
CONFIGURE_ARGS+=	--without-python
.endif

LICENSE=	GPLv2

MAN1=		honeydctl.1
MAN8=		honeyd.8

NO_STAGE=	yes
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
	@${MKDIR} ${DATADIR}/webserver

post-install:
	@${MKDIR} ${DATADIR}/scripts/snmp
	@cd ${WRKSRC}/scripts && \
		${INSTALL_DATA} README* INSTALL* kuang2.conf \
			${DATADIR}/scripts && \
		${INSTALL_SCRIPT} *.pl *.sh ${DATADIR}/scripts
	@cd ${WRKSRC}/scripts/snmp && \
		${INSTALL_DATA} README default.snmp *.tpl \
			${DATADIR}/scripts/snmp && \
		${INSTALL_SCRIPT} *.pl ${DATADIR}/scripts/snmp

.include <bsd.port.post.mk>
