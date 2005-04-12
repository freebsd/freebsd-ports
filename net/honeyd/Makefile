# New ports collection makefile for:	honeyd
# Date created:				16/04/2002
# Whom:				Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	honeyd
PORTVERSION=	0.8b
CATEGORIES=	net
MASTER_SITES=	http://www.citi.umich.edu/u/provos/honeyd/ \
		http://niels.xtdnet.nl/honeyd/

MAINTAINER=	yb@bashibuzuk.net
COMMENT=	Simulate virtual network hosts (honeypots)

BUILD_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet \
		${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent

#OPTIONS=	PYTHON "Enable Python support" off
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-libdnet=${LOCALBASE} \
		--with-libevent=${LOCALBASE} \
		--with-pcap

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--with-python
.else
CONFIGURE_ARGS+=	--without-python
.endif

MAN1=		honeydctl.1
MAN8=		honeyd.8

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500000
LIB_DEPENDS+=	edit.5:${PORTSDIR}/devel/libedit
.endif

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

post-install:
	@${MKDIR} ${DATADIR}/scripts/snmp
	@cd ${WRKSRC}/scripts && \
		${INSTALL_SCRIPT} *.pl *.sh ${DATADIR}/scripts
	@cd ${WRKSRC}/scripts/snmp && \
		${INSTALL_DATA} README default.snmp *.tpl \
			${DATADIR}/scripts/snmp && \
		${INSTALL_SCRIPT} *.pl ${DATADIR}/scripts/snmp

.include <bsd.port.post.mk>
