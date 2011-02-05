# Ports collection makefile for:	ssltunnel-client
# Date created:			June 10, 2003
# Whom:				at@rominet.net
#
# $FreeBSD$
#

PORTNAME=	ssltunnel
PORTVERSION=	1.18
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.hsc.fr/ressources/outils/ssltunnel/download/
PKGNAMESUFFIX=	-client

MAINTAINER=	utisoft@gmail.com
COMMENT=	PPP over SSL virtual private networking (client part)

LICENSE=	BSD

CONFIGURE_ARGS=	--disable-server --with-iconv=${LOCALBASE}
GNU_CONFIGURE=	yes
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
USE_GNOME=	gtk12
USE_PERL5=	yes
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk
MAN1+=		gpppclient.1
BUILD_PERLGTK=	yes
.endif

post-patch:
	${REINPLACE_CMD} -e 's|with_iconv|with-iconv|g' ${WRKSRC}/configure

post-install:
.if defined(BUILD_PERLGTK)
	${ECHO_CMD} "bin/gpppclient" >> ${TMPPLIST}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/LISEZ-MOI ${DOCSDIR}/client.LISEZ-MOI
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}/client.README
.endif
	@${MKDIR} ${ETCDIR}/
	${INSTALL_DATA} ${WRKSRC}/client/tunnel.conf ${ETCDIR}/client.conf.sample

.include <bsd.port.post.mk>
