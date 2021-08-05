PORTNAME=	rscsi
CATEGORIES=	net

COMMENT=	Remote SCSI transport server program (daemon)

CONFLICTS=	cdrtools-devel

USERS=		rscsi
GROUPS=		rscsi

MASTERDIR=	${.CURDIR}/../../devel/schilybase
COMPONENTS=	rscsi

SUB_FILES=	pkg-message.rscsi
PKGMESSAGE=	${WRKDIR}/pkg-message.rscsi

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/cdrecord/README.rscsi ${STAGEDIR}${DOCSDIR}/

.include "${MASTERDIR}/Makefile.master"
