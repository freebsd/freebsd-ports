# $FreeBSD$
#

.PATH:		${FILESDIR}

PREFIX?=	/usr/local
BINDIR=		${PREFIX}/bin
MANDIR=		${PREFIX}/man/man
PROG_CXX=	spamprobe
CXXFLAGS+=	-Wall -DUSE_DB -I${PREFIX}/include/db3
LDFLAGS=	-L${PREFIX}/lib -ldb3 -lmd
SRCS=		File.cc FrequencyDB.cc FrequencyDBImpl_bdb.cc \
		FrequencyDBImpl_cache.cc FrequencyDBImpl_dbm.cc LockFile.cc \
		Message.cc MessageFactory.cc MimeHeader.cc MimeLineReader.cc \
		MimeMessageReader.cc SpamFilter.cc Tokenizer.cc \
		spamprobe.cc util.cc

.include <bsd.prog.mk>
