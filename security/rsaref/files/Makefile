O= o
SO= so
LIB= ar

.SUFFIXES: .c .so .o

.c.so:
	${CC} -fpic -DPIC ${CFLAGS} -c ${.IMPSRC} -o ${.TARGET}

RSAREFLIB=librsaref.a
.if ${PORTOBJFORMAT} == elf
SORSAREFLIB=librsaref.so.2
.else
SORSAREFLIB=librsaref.so.2.0
.endif

all: ${RSAREFLIB} ${SORSAREFLIB}

$(RSAREFLIB) : desc.$(O) digit.$(O) md2c.$(O) md5c.$(O) nn.$(O) prime.$(O)\
  rsa.$(O) r_encode.$(O) r_dh.$(O) r_enhanc.$(O) r_keygen.$(O) r_random.$(O)\
  r_stdlib.$(O)
	$(LIB) rc $@ $>
	ranlib $@

$(SORSAREFLIB) : desc.$(SO) digit.$(SO) md2c.$(SO) md5c.$(SO) nn.$(SO) prime.$(SO)\
  rsa.$(SO) r_encode.$(SO) r_dh.$(SO) r_enhanc.$(SO) r_keygen.$(SO) r_random.$(SO)\
  r_stdlib.$(SO)
.if ${PORTOBJFORMAT} == elf
	${CC} -o $@ -shared -Wl,-soname,$@ $>
.else
	ld -Bshareable -x -o $@ $>
.endif

install:
	install -c -m 444 -o bin -g bin rsa.h _des.h _md2.h _md5.h rsaref.h global.h ${PREFIX}/include
.if ${PORTOBJFORMAT} == elf
	install -c -m 644 -o bin -g bin librsaref.a librsaref.so.2 ${PREFIX}/lib
	(cd ${PREFIX}/lib; ln -sf librsaref.so.2 librsaref.so)
.else
	install -c -m 644 -o bin -g bin librsaref.a librsaref.so.2.0 ${PREFIX}/lib
	(cd ${PREFIX}/lib; ln -sf librsaref.so.2.0 librsaref.so)
.endif
