# Common file for CUPS ports
# $FreeBSD$

MASTER_SITES=	ftp://ftp.easysw.com/pub/cups/${CUPS_VERSION}/ \
		ftp://ftp2.easysw.com/pub/cups/${CUPS_VERSION}/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/cups/${CUPS_VERSION}/ \
		ftp://ftp.mpg.goe.ni.schule.de/pub/internet/printing/cups/${CUPS_VERSION}/

CUPS_VERSION=	1.1.14

#protect the base port
.if( $(PORTNAME) != "cups")
DISTNAME=	cups-${CUPS_VERSION}-source
DISTFILES=	${DISTNAME}.tar.bz2
WRKSRC=		${WRKDIR}/cups-${CUPS_VERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+= --localstatedir=/var
.endif

