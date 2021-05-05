# Created by: Sander Vesik <sander@haldjas.folklore.ee>

PORTNAME=	tkcron
PORTVERSION=	2.12
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.tcl.tk/pub/tcl/mirror/ftp.procplace.com/sorted/packages-7.6/misc/tkcron-2.12/ \
		http://ftp.sunet.se/pub/lang/tcl/sorted/packages-7.6/misc/tkcron-2.12/ \
		http://ftp4.de.freesbie.org/pub/misc/x11/tcl/ftp.gmd.de/contrib/sorted/misc/tkcron-2.12/ \
		http://komquats.com/distfiles/ \
		http://people.freebsd.org/~cy/distfiles/
EXTRACT_SUFX=	.tcl.gz

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Frontend to crontab

USES=		tk:,run

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS= -cd
EXTRACT_AFTER_ARGS= > tkcron.tcl
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/tkcron

post-patch:
	${REINPLACE_CMD} -e 's|%%WISH%%|${WISH}|' ${WRKSRC}/tkcron.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkcron.tcl ${STAGEDIR}${PREFIX}/bin/tkcron

.include <bsd.port.mk>
