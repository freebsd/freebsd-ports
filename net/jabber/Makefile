# New ports collection makefile for:	jabber
# Date created:			5 February 2001
# Whom:				joe
#
# $FreeBSD$
#

PORTNAME=	jabber
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://download.jabber.org/dists/1.4/final/ \
		http://download.jabber.org/dists/transports/aim-transport/ \
		http://download.jabber.org/dists/transports/yahoo-transport/ \
		http://download.jabber.org/dists/transports/irc-transport/
DISTFILES+=	jabber-1.4.1.tar.gz \
		aim-transport-0.9.24c.tar.gz \
		conference-0.4.1.tar.gz \
		icq-transport-0.9.tar.gz \
		irc-transport-0.1.1-1.4.linux.tar.gz \
		jud-0.4.tar.gz \
		msn-transport-1.1.tar.gz \
		yahoo-transport-0.8-1.4.linux.tar.gz

MAINTAINER=	sean@chittenden.org

LIB_DEPENDS=	pth.14:${PORTSDIR}/devel/pth

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes

CONFIGURE_ARGS+=	--enable-ssl

rc=${PREFIX}/etc/rc.d

JABDIR=		${PORTNAME}-${PORTVERSION}
post-extract:
	@mv ${WRKDIR}/aim-transport-0.9.24c ${WRKDIR}/${JABDIR}/aim-transport
	@mv ${WRKDIR}/conference-0.4.1 ${WRKDIR}/${JABDIR}/conference
	@mv ${WRKDIR}/icq-transport-0.9 ${WRKDIR}/${JABDIR}/icq-transport
	@mv ${WRKDIR}/irc-transport-0.1.1-1.40 ${WRKDIR}/${JABDIR}/irc-transport
	@mv ${WRKDIR}/jud-0.4 ${WRKDIR}/${JABDIR}/jud
	@mv ${WRKDIR}/msn-transport-1.1 ${WRKDIR}/${JABDIR}/msn-transport
	@mv ${WRKDIR}/yahoo-transport-0.8-1.4 ${WRKDIR}/${JABDIR}/yahoo-transport

post-configure:
	${SETENV} CC="${CC}" CFLAGS="${CFLAGS}" \
		CPPFLAGS="`pth-config --cflags` `libxode-config --cflags`" \
		LDFLAGS="`pth-config --ldflags` `libxode-config --ldflags`" \
		LIBS="`pth-config --libs` `libxode-config --libs`" ${SHELL} -c \
	"cd ${WRKDIR}/${JABDIR}/aim-transport; ./configure --with-jabberd=${WRKDIR}/${JABDIR}/jabberd; \
	 cd ${WRKDIR}/${JABDIR}/irc-transport;  \
		./configure --includedir=${WRKDIR}/${JABDIR}/jabberd; \
	 cd ${WRKDIR}/${JABDIR}/yahoo-transport; \
	 	./configure --includedir=${WRKDIR}/${JABDIR}/jabberd"

post-install:
	@PREFIX=${PREFIX} ${PERL5} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_SCRIPT} ${FILESDIR}/jabberd.sh ${rc}

.include <bsd.port.mk>
