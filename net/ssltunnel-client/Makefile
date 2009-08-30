# ex:ts=8
# Ports collection makefile for:	ssltunnel-client
# Date created:			June 10, 2003
# Whom:				at@rominet.net
#
# $Id: Makefile,v 1.3 2003/09/21 16:20:44 thivillon Exp $
#
# $FreeBSD$
#

PORTNAME=	ssltunnel
PORTVERSION=	1.16
CATEGORIES=	net
MASTER_SITES=	http://www.hsc.fr/ressources/outils/ssltunnel/download/
PKGNAMESUFFIX=	-client

MAINTAINER=	at@rominet.net
COMMENT=	PPP over SSL virtual private networking (client part)

USE_ICONV=	yes

MAN1=		pppclient.1
MAN5=		ssltunnelrc.5

WANT_GNOME=	yes
WANT_PERL=	yes

.if defined(PACKAGE_BUILDING)
WITHOUT_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME=gtk12
USE_PERL5=yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk
MAN1+=	gpppclient.1
BUILD_PERLGTK=yes
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-server --with-iconv=${LOCALBASE}

post-install:
.if defined(BUILD_PERLGTK)
	${ECHO_CMD} "bin/gpppclient" >> ${TMPPLIST};
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/LISEZ-MOI ${DOCSDIR}
.endif
	@${MKDIR} ${PREFIX}/etc/ssltunnel/
	${INSTALL_DATA} ${WRKSRC}/client/tunnel.conf ${PREFIX}/etc/ssltunnel/client.conf.sample

.include <bsd.port.post.mk>
