# Created by: Sander Vesik <sander@haldjas.folklore.ee>
# $FreeBSD$

PORTNAME=	tkcron
PORTVERSION=	2.12
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.tcl.tk/pub/tcl/mirror/ftp.procplace.com/sorted/packages-7.6/misc/tkcron-2.12/ \
		http://ftp.sunet.se/pub/lang/tcl/sorted/packages-7.6/misc/tkcron-2.12/ \
		http://ftp4.de.freesbie.org/pub/misc/x11/tcl/ftp.gmd.de/contrib/sorted/misc/tkcron-2.12/ \
		http://komquats.com/distfiles/ \
		http://people.freebsd.org/~cy/distfiles/
EXTRACT_SUFX=	.tcl.gz

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A frontend to crontab

RUN_DEPENDS=	wish8.5:${PORTSDIR}/x11-toolkits/tk85 \
		wish:${PORTSDIR}/x11-toolkits/tk-wrapper 

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS= -cd
EXTRACT_AFTER_ARGS= > tkcron.tcl
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/tkcron

NO_STAGE=	yes
post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
