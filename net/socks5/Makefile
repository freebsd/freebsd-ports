# New ports collection makefile for:	socks5
# Date created:				24 Apr 1996
# Whom:					pst
#
# $FreeBSD$
#

PORTNAME=	socks5
PORTVERSION=	1.0.11
PORTREVISION=	5
CATEGORIES=	net security
MASTER_SITES=	http://reality.sgiweb.org/freeware/source/socks5/ \
		http://freeware.sgi.com/source/socks5/
DISTNAME=	socks5-v1.0r11

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	SOCKS v5 application layer gateway and clients

USE_RC_SUBR=	${PORTNAME}.sh
NO_CDROM=	NEC has a funky license for this software
RESTRICTED=	no commercial use

CONFLICTS=	dante-[0-9]*

# here are some extra configure args you may wish to use
# see the readme file before screwing with them
#
#EXTRA_CONFIGURE_ARGS= \
#		--with-default-server=socks.mydomain.com \
#		--with-syslog-facility=LOG_AUTH \
#		--with-passwd

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-DHAVE_VSNPRINTF
CONFIGURE_ARGS=	--with-libconffile=${PREFIX}/etc/libsocks5.conf \
		--with-srvconffile=${PREFIX}/etc/socks5.conf \
		--with-srvpidfile=/var/run/socks5.pid \
		--with-srvidtfile=/var/run/socks5.ident \
		--with-srvpwdfile=${PREFIX}/etc/socks5.passwd \
		${EXTRA_CONFIGURE_ARGS}
MAN1=		runsocks.1 socks5.1 stopsocks.1 socks5_clients.1
MAN5=		libsocks5.conf.5 socks5.conf.5 socks5.passwd.5
CONFIGURE_ENV=	LIBS=-lcrypt

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
