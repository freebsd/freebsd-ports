PORTNAME=	cdrtools
CATEGORIES=	sysutils audio

COMMENT=	Tools for ripping from and recording to CDs and DVDs

LAME_RUN_DEPENDS=	lame:audio/lame
VORBIS_RUN_DEPENDS=	oggenc:audio/vorbis-tools

USES=		cpe

CPE_VENDOR=	cdrtools_project

OPTIONS_DEFINE=	DOCS LAME VORBIS SETUID
OPTIONS_DEFAULT=DOCS LAME VORBIS
OPTIONS_SUB=	yes
LAME_DESC=	Install cdda2mp3 (requires audio/lame)
VORBIS_DESC=	Install cdda2ogg (requires audio/vorbis-tools)
SETUID_DESC=	Install cdrecord, cdda2wav, and readcd as setuid root
SETUID_PLIST_SUB=	SUID="@(root,,4711) "
SETUID_PLIST_SUB_OFF=	SUID="@(,,755) "

CONFLICTS_INSTALL=	cdrkit

MASTERDIR=	${.CURDIR}/../../devel/schilybase
COMPONENTS=	cdda2wav \
		cdrecord \
		mkisofs \
		mkisofs/diag \
		readcd \
		scgcheck \
		scgskeleton

post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/doc/cdrecord/README.rscsi

post-install-LAME-off:
	${RM} ${STAGEDIR}${PREFIX}/bin/cdda2mp3 ${STAGEDIR}${PREFIX}share/man/man1/cdda2mp3.1

post-install-VORBIS-off:
	${RM} ${STAGEDIR}${PREFIX}/bin/cdda2ogg ${STAGEDIR}${PREFIX}share/man/man1/cdda2ogg.1

post-install-DOCS-off:
	${RM} ${STAGEDIR}share/doc

.include "${MASTERDIR}/Makefile.master"
