# $FreeBSD$
#

.PATH:		${FILESDIR}

PREFIX?=	/usr/local
BINDIR=		${PREFIX}/bin
MANDIR=		${PREFIX}/man/man
PROG_CXX=	spamprobe
CXXFLAGS+=	-Wall -I${PREFIX}/include/db4 -DNDEBUG \
		-DPACKAGE=\"spamprobe\" -DVERSION=\"0.8b\" \
		-DHAVE_UNISTD_H=1 -DHAVE_REGEX_H=1 -DUSE_DB=1
CFLAGS+=	-Wall -I${PREFIX}/include/db4 -DNDEBUG \
		-DPACKAGE=\"spamprobe\" -DVERSION=\"0.8b\" \
		-DHAVE_UNISTD_H=1 -DHAVE_REGEX_H=1 -DUSE_DB=1
LDFLAGS=	-L${PREFIX}/lib -ldb4
SRCS=		File.cc FrequencyDB.cc FrequencyDBImpl_bdb.cc \
		FrequencyDBImpl_cache.cc FrequencyDBImpl_dbm.cc \
		FrequencyDBImpl_dual.cc LockFile.cc Message.cc \
		MessageFactory.cc MimeHeader.cc MimeLineReader.cc \
		MimeMessageReader.cc RegularExpression.cc SpamFilter.cc \
		Tokenizer.cc spamprobe.cc util.cc md5.c

.include <bsd.prog.mk>
