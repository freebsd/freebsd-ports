# New ports collection makefile for:	pdflib
# Date created:		Wed Jan 9 12:27:54 CET 2002
# Whom:			Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	pdflib
PORTVERSION=	7.0.4
CATEGORIES=	print
MASTER_SITES=	http://www.pdflib.com/binaries/PDFlib/${PORTVERSION:S/.//g}/
DISTNAME=	PDFlib-Lite-${PORTVERSION}p4

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A C library for dynamically generating PDF

RESTRICTED=	many odd restrictions on usage and distribution

USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--with-java=no --with-py=no --with-ruby=no --with-tcl=no

.if defined(WITH_PERL)
USE_PERL5=	yes
PLIST_SUB=	PERL=""
CONFIGURE_ARGS+=--with-perl=${PERL}
PKGNAMESUFFIX=	-perl
.else
CONFIGURE_ARGS+=--with-perl=no
PLIST_SUB=	PERL="@comment "
.endif

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "sparc64"
CONFIGURE_ARGS+=--enable-64bit
.endif
post-patch:
	@${REINPLACE_CMD} -e "s|\(PDFLIB_LTCURRENT\)=6|\1=8|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's^\$$(top_builddir)/libtool^${LIBTOOL}^' ${WRKSRC}/config/mkcommon.inc.in

post-install:
	${MKDIR} ${DATADIR}/fonts
	${INSTALL_DATA} ${WRKSRC}/fonts/* ${DATADIR}/fonts
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pdflib/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
