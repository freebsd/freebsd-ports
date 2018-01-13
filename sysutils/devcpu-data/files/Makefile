AMD_UCODE_DIR=	amd64-microcode-3.20171205.1
AMD_UCODE=	$(AMD_UCODE_DIR)/microcode_amd.bin \
		$(AMD_UCODE_DIR)/microcode_amd_fam15h.bin \
		$(AMD_UCODE_DIR)/microcode_amd_fam16h.bin \
		$(AMD_UCODE_DIR)/microcode_amd_fam17h.bin
INTEL_UCODE=	microcode.dat
OUTPUT_DIR=	mcodes
all:	ucode
ucode:	ucode-tool
	mkdir -p $(OUTPUT_DIR)
	./ucode-tool -o $(OUTPUT_DIR) -i $(INTEL_UCODE)
	mv ${AMD_UCODE} $(OUTPUT_DIR)

# Use the host cc to compile ucode-tool in case of cross-compile
ucode-tool: ucode-tool.c
	cc ucode-tool.c -o $@

clean:
	rm -rf $(OUTPUT_DIR) ucode-tool
