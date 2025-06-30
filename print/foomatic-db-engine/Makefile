PORTNAME=	foomatic-db-engine
PORTVERSION=	4.0.13
PORTREVISION=	4
PORTEPOCH=	2
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/foomatic/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Foomatic database engine
WWW=		https://www.linuxprinting.org/foomatic.html

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gmake gnome perl5
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	PERL=${PERL} LIBDIR=${PREFIX}/share/foomatic/ \
		LIB_CUPS=${LOCALBASE}/libexec/cups \
		CUPS_FILTERS=${LOCALBASE}/libexec/cups/filters \
		CUPS_BACKENDS=${LOCALBASE}/libexec/cups/backends

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		"s,sysconfdir=/etc,sysconfdir=\'${PREFIX}/etc\',g ; \
		 s,/usr/local/etc:,${PREFIX}/etc:,g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		"s,/usr/local/bin:,${PREFIX}/bin:,g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		"/if \[ -d/ s,LIB_CUPS,PREFIX," ${WRKSRC}/Makefile.in

post-install:
.for file in foomatic-combo-xml foomatic-perl-data
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
