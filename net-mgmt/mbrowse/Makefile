# New ports collection makefile for:	mbrowse
# Date created:			Apr 4, 2002
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	mbrowse
PORTVERSION=	0.2.3
CATEGORIES=	net
MASTER_SITES=	http://goldplated.atlcartel.com/

MAINTAINER=	markp@FreeBSD.org

LIB_DEPENDS=	snmp.4:${PORTSDIR}/net/net-snmp4

GNU_CONFIGURE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
CONFIGURE_ARGS+=	--with-ucdsnmp-prefix=${LOCALBASE}

post-patch:
	@${PERL} -pi -e 'print "#include <sys/types.h>\n" if !$$a; $$a=1' \
		${WRKSRC}/src/callbacks.h

.include <bsd.port.mk>
